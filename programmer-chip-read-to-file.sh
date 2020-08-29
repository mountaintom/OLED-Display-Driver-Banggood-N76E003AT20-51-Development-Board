#!/bin/bash

##download-ms51:
##        nuvoprog-dev read ./downloaded-flash-read-ms51.ihx --target ms51fb9ae && \
##        nuvoprog-dev image split -i ./downloaded-flash-read-ms51.ihx --target ms51fb9ae  -a downloaded-program-flash-data-ms53.ihx -l downloaded-loader-flash-data-ms51.ihx -c downloaded-chip-configuration-ms51.json && echo "Done!!"

##TIME=`date +%Y-%m-%d.%H:%M:%S`
TIME=`date +%Y%m%d-%H%M%S`
FILES_PATH="./programmer/programmer-chip-read-files"
echo
echo "Trying ms51fb9ae device"
echo
##download-ms51:
if nuvoprog-dev read $FILES_PATH/downloaded-all-flash-read-ms51-$TIME.ihx --target ms51fb9ae ; then
    nuvoprog-dev image split -i $FILES_PATH/downloaded-all-flash-read-ms51-$TIME.ihx --target ms51fb9ae  -a $FILES_PATH/downloaded-program-flash-data-ms51-$TIME.ihx -l $FILES_PATH/downloaded-loader-flash-data-ms51-$TIME.ihx -c $FILES_PATH/downloaded-chip-configuration-ms51-$TIME.json && \
    (echo ; echo "\ms51fb9ae device success" ; echo)
    else
echo
echo "Trying n76003  device"
echo
##download-n76:
    nuvoprog-dev read $FILES_PATH/downloaded-all-flash-read-n76-$TIME.ihx --target n76e003 &&\
    nuvoprog-dev image split -i $FILES_PATH/downloaded-all-flash-read-n76-$TIME.ihx --target n76e003  -a $FILES_PATH/downloaded-program-flash-data-n76-$TIME.ihx -l $FILES_PATH/downloaded-loader-flash-data-n76-$TIME.ihx -c $FILES_PATH/downloaded-chip-configuration-n76-$TIME.json && \
     (echo ; echo "76003 device success" ; echo)
fi      

