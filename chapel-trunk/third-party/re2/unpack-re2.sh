#!/bin/sh

if [ -d re2 ]
then

echo RE2 already unpacked

else

echo Unpacking RE2
tar xzf re2-20130802.tgz
echo Applying Patches
cd re2
patch -p1 < ../hg_diff_g.patch
echo Copying file_strings.h and file_strings.cc
cp ../file_strings.h re2/
cp ../file_strings.cc re2/
fi
