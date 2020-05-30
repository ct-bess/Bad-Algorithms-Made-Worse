#!/bin/bash

#seq 15 | awk '{ printf "%3d: ", NR } NR % 3 == 0 { printf "Fizz" } NR % 5 == 0 { printf "Buzz" } { printf "\n" }'

COUNT=15
TYPES=(
  'awk modulo'
  'sed line counting'
)

if [ "$1" -a "`echo $1 | grep [0-9+]`" ]; then
  COUNT=$1
fi
  
PS3="Pick your FizzBuzz type : "
select FIZZBUZZ in ${TYPES[*]} quit; do
  case $FIZZBUZZ in
    ${TYPES[0]})
      echo -en "Picked \033[01;38msed\033[00m\n"
      seq $COUNT | sed "n;n;s/[0-9]*$/Fizz/" | sed "n;n;n;n;s/[0-9]*$/Buzz/"
      echo
      ;;
    ${TYPES[1]})
      echo -en "Picked \033[01;38mawk\033[00m\n"
      seq $COUNT | awk 'NR % 3 == 0 { printf "Fizz"; s = 1 } NR % 5 == 0 { printf "Buzz"; s = 1 } s != 1 { printf "%d", NR }; { printf "\n"; s = 0 }'
      echo
      ;;
    'quit')
      break
      ;;
    *)
      echo "That FizzBuzz type doesn't exist here"
      echo -en "Choices: \033[01;34m${TYPES[*]}\033[00m\n"
      echo "(press ENTER to see the list with the numbers)"
      echo
      ;;
  esac
done

