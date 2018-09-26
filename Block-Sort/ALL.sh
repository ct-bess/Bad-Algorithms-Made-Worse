#!/bin/bash

for ((i=1; i<=53; i++))
do
  ./main "$i"
done

echo "Done"
