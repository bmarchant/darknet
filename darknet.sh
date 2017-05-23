#~/bin/bash

if [ $# -ne 5 ]; then
  echo "Usage: darknet.sh <data> <config> <weights> <input_dir> <output_dir>"
  exit
fi

for f in $4*.jpg ;
do
  file=$(basename "$f")
  echo $file
  ./darknet detector test $1 $2 $3 $4$file -out $5$file.detections -i 0 -thresh 0.25 1> $5$file.detections.txt 2>/dev/null;
done
