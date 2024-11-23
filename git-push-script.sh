#!/bin/sh
filename=$(ls -t1 | head -1)
msg=$(head -n 2 $filename | tail -1)
echo $filename
echo $msg
$(git add $filename)
git status
# git commit -m $msg
# git push