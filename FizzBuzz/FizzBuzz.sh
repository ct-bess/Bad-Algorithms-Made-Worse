seq 100 | sed "n;n;s/[0-9]*$/Fizz/" | sed "n;n;n;n;s/[0-9]*$/Buzz/"
