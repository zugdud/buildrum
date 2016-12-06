#!/bin/bash

set -x

FILE_NAME=/tmp/buildrum_`date +%Y-%m-%d_%H-%M-%S`.tar
cd /home/jcreecy/code/
tar -cvf $FILE_NAME buildrum/
gzip $FILE_NAME

cp ${FILE_NAME}.gz /media/jcreecy/GUINEAPIG/backups/
