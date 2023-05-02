#!/bin/bash

topics=("C" "Arrays" "Algorithms" "Memory" "Data Structures" "Python" "SQL" "HTML, CSS, JavaScript" "Flask" "Emoji")

for i in {1..10}
do
  folder_name="Problem Set $i: ${topics[$i-1]}"
  mkdir "$folder_name"
done
