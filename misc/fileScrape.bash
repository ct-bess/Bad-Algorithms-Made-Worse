#!/bin/bash

IFRE="*\.js"
searchRE="var.+"
OF="results.txt"

echo > $OF

if [ "$1" ]; then
  echo "Directory: $1" >> $OF
  echo >> $OF
else
  echo "Usage: fileScraper [directory]"
  exit
fi

echo "Scrape Started..."

for i in `find $1 -iname "$IFRE"` ; do
  echo "File: $i" >> $OF
  match=`cat $i | grep -oP "$searchRE"`
  echo $match | sed "s/;/;\n/g" >> $OF
  echo >> $OF
done

echo -en "Scrape Resuls: \033[01;36m$OF\033[00m\n"

