# Example file of how I use my handleCommas() function
# Linux: gawk -f NoCommas.awk test.csv
# Windows with gitbash: awk -f NoCommas.awk test.csv
BEGIN {
  print "Starting test ..."
  FS = ","
}

# this function searches the current record for nested csv's
# i.e. not nested,"but,this,is,nested",
# creates 2 variables with it's findings:
# nestedOffset: an array of ints with the same length as the original csv headers
#   It's meant ot keep track of how many extra commas we need to access each column in the record
# nestedRecords: an array of strings that stores the nested csv record for us to use
#   This let's us manipulate the nested record as 1 string rather than multiple
function handleCommas() {

  split( $0, a, "," )
  size = length( a )
  quoteFlag = 0
  nestedCsv = ""
  prevHeaderIndex = 0
  delete nestedOffset
  delete nestedRecords

  for( i = 1; i < size + 1; ++i ) {

    charFirst = substr( $i, 1, 1 )
    charLast = substr( $i, length( $i ), length( $i ) )

    # we are in a nested record
    if( quoteFlag == 1 ) {
      nestedCsv = nestedCsv "," $i
      ++nestedOffset[headerIndex]
      # Exit point for nested records
      if( charLast == "\"" ) {
        # remove those pesky double quotes from our output
        nestedCsv = substr( nestedCsv, 2, length( nestedCsv ) - 2 )
        nestedRecords[mapping] = nestedCsv
        quoteFlag = 0
      }
    }

    # Entry point for nested records
    else if( charFirst == "\"" ) {
      nestedCsv = $i
      headerIndex = i
      # align headerIndex to previous index
      if( i > 1 && prevHeaderIndex > 0 ) {
        headerIndex = headerIndex - int( nestedOffset[prevHeaderIndex] )
      }
      mapping = headers[headerIndex]
      nestedOffset[headerIndex] = nestedOffset[prevHeaderIndex]
      prevHeaderIndex = headerIndex
      quoteFlag = 1
    }

  } # EO record's loop

  # -- ending procedures

  # nested record is size 1 or wasn't terminated properly
  if( quoteFlag == 1 ) {
    nestedCsv = substr( nestedCsv, 2, length( nestedCsv ) - 2 )
    nestedRecords[mapping] = nestedCsv
    quoteFlag = 0
  }

  # always catch up the offset array; b/c there's no guarentee it's in sync
  for( i = 1; i < length( headers ); ++i ) {
    if( !nestedOffset[i] ) {
      nestedOffset[i] = nestedOffset[i-1]
    }
  }


} # EO handleCommas()

# -- General rules

# Typically CSV headers
FNR == 1 && FILENAME == "test.csv" {
  # For this function to work, we need to store the headers at the start of each new file
  print "Storing headers"
  split( $0, a, "," )
  size = length( a )
  for( i = 1; i < size + 1; ++i ) {
    headers[i] = $i
  }
}

# Typically CSV rows
FNR > 1 && FILENAME == "test.csv" {
  print "---"
  print "Entire record:", $0
  # You call handleCommas for each record
  handleCommas()
  # it'll create the nested offset and records variables to use
  print "Just Column1:", $1
  print "Column1 using nested records:", nestedRecords["Column1"]
  if( !!nestedRecords["Column1"] ) {
    print "Column1 was a nested record"
  }
  else {
    print "Column1 was not a nested record"
  }

  # Ok cool, but what if we need to grab column 3, but the nested csv messed everything up?
  # use the nested offset to point us in the right place. If there is no nested record at or before our index the offset will be zero
  print "Just Column3:", $3
  print "Column3 using nested offset =", nestedOffset[3]":", $(3 + nestedOffset[3])
  print "Column3 using nested records:", nestedRecords["Column3"]

  # So how is this helpful?
  # suppose column 5 is some kind of number identifier
  # and column 4 is a tag for that identifier
  # and finally column 6 is some *real* data for that identifier
  # Let's say our goal is to organize this data by id, then take an average of this alledged *real* data

  # If we hadn't accounted for nested records in the previous columns our indicies would be messed up
  col5 = $(5 + nestedOffset[5])
  print "Column5:", col5

  # So we add the tags to our data
  if( !!nestedRecords["Column4"] ) {
    data[col5]["tags"] = nestedRecords["Column4"] "," data[col5]["tags"]
  }
  else {
    data[col5]["tags"] = $(4 + nestedOffset[4]) "," data[col5]["tags"]
  }

  # then we add the *re*al data part
  if( !!nestedRecords["Column6"] ) {
    split( nestedRecords["Column6"], a, "," )
    for( i in a ) {
      data[col5]["real data sum"] += int( i )
    }
    data[col5]["real data records"] += length( a )
  }
  else {
    data[col5]["real data sum"] += int( $(6 + nestedOffset[6]) )
    data[col5]["real data records"] += 1
  }

}

END {
  print "\nAnd here's our nice clean data:\n"
  for( id in data ) {
    print "id "id":"
    # take int( x + 0.5 ) to round at 0.5
    data[id]["real data avg"] = data[id]["real data sum"] / data[id]["real data records"]
    for( key in data[id] ) {
      print key":", data[id][key]
    }
  }
  print "\ntest done"
}
