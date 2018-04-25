#!/bin/sh
outf=upfiles_fillit
find . -type f | grep -v .git | grep -v upfiles | grep -v .DS_Store | sed 's|\./||g' > $outf
echo "gen_upfiles.sh" >> $outf
echo "$outf" >> $outf
