#!/usr/bin/env bash

(awk 'BEGIN{ p = 1 }/Day/{ p = 0 }{ if (p == 1) { print } }' README.md
 header="Day | Lines | sloc | Bytes | Source"
 echo $header
 echo $header | sed 's/[^|]/-/g'
 for i in src/*.cpp
 do
     (echo $i | sed -r 's/[^0-9]+//g'
      echo "|"
      grep -c '^' $i
      echo "|"
      grep -c '.' $i
      echo "|"
      wc -m < $i
      echo "|"
      echo $i | sed -r 's|(.*)/(.*)|[\2](https://github.com/willkill07/adventofcode/blob/master/\1/\2)|'
     ) | paste -sd' '
 done | awk 'BEGIN{ l = 0; s = 0; b = 0 }{ l += $3; s += $5; b += $7; print }END{ print "**TOTAL** | **" l "** | **" s "** | **" b "** |" }') > README2.md && mv README{2,}.md
