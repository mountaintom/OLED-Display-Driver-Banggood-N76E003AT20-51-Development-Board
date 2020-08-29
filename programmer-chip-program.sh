#!/bin/bash

for direntry in ./prj-main/*.c
do
  HEX_FILE_PATH=./prj-build/`basename $direntry .c`.ihx
  echo
  echo "Found main file: $direntry"
  echo "Will  program chip from file: $HEX_FILE_PATH"
  echo
done

echo "*** Trying ms51fb9ae device ***"
echo
##program-MS51:
if nuvoprog-dev program -t ms51fb9ae -a $HEX_FILE_PATH -c @./programmer/config-ms51.json -v ; then
  (echo ; echo "\ms51fb9ae device success" ; echo)
else
  echo
  echo "*** ms51fb9ae device did not succed ***"
  echo "*** Trying n76e003 device ***"
  echo
  ##program-n76: 
  nuvoprog-dev program -t n76e003 -a $HEX_FILE_PATH -c @./programmer/config-n76.json -v && \
    (echo ; echo "76003 device success" ; echo)
fi

