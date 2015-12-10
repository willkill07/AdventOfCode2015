# Advent of Code - 2015

All implementations are written in C++, strictly adhering to C++11/14 guidelines.

### Metrics

* Lines: Number of lines given by `wc`
* Code: `Lines` - `(# preprocessor lines)` - `(lines with no alphanumeric chars)`
* Bytes: Number of total characters
* Chars: Number of non-whitespace characters
* Time: Time in seconds to execute each part independently (separate runs)
* Source: link to implementation
* Headers: C++ includes used for solution

### Leaderboard Highlights:

* Day 5: Placed #60
* Day 8: Placed #14
* Day 10: Placed #64

### Non C++ Stuff

##### Day 1 (Part 1): Bash-ism (83 chars)

```bash
(paste -s<(tr -dc '('<input1.txt|wc -c)<(tr -dc ')'<input1.txt|wc-c))|paste -sd-|bc
```

##### Day 2 (Part 1): Bash-ism (123 chars)

```bash
<input2.txt while read line; do tr x \\n <<<$line|sort -n|paste -s|awk '{print 3*($1*$2)+2*$3*($1+$2);}';done|paste -sd+|bc
```

##### Day 10: Bash-ism (74 chars)

Note: `s` needs to contain the input string

```bash
for i in `seq 40`;do s=`fold -w1<<<$s|uniq -c|tr -d '\n '`;done;wc -c<<<$s
```

### Detailed Information

 Day | Lines | Code | Bytes | Chars | Time | Source | Headers
:---:|:-----:|:----:|:-----:|:-----:| ----:|:------:|:-------
1|18|12|367|257|0.0030|[day1.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day1/day1.cpp)|`iostream`
2|22|13|656|515|0.0059|[day2.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day2/day2.cpp)|`algorithm` `iostream` `regex` `string`
3|30|19|675|512|0.0072|[day3.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day3/day3.cpp)|`iostream` `map` `tuple`
4|17|10|498|394|0.5068|[day4.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day4/day4.cpp)|`iostream` `string`
5|17|9|626|515|0.0616|[day5.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day5/day5.cpp)|`iostream` `regex` `string`
6|61|40|1714|1292|0.4871|[day6.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day6/day6.cpp)|`functional` `future` `iostream` `iterator` `regex` `string` `vector`
7|78|54|2217|1598|0.0134|[day7.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day7/day7.cpp)|`iostream` `map` `regex` `string`
8|27|13|855|666|0.0060|[day8.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day8/day8.cpp)|`iostream` `iterator` `numeric` `regex` `string`
9|36|23|1070|844|0.0807|[day9.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day9/day9.cpp)|`iostream` `limits` `map` `numeric` `set` `string` `vector`
10|23|13|593|448|1.9848|[day10.cpp](https://github.com/willkill07/adventofcode/blob/master/src/day10/day10.cpp)|`algorithm` `functional` `iostream` `sstream` `string`
**TOTAL**|**329**|**206**|**9271**|**7041**|**3.1565**| | `algorithm` `functional` `future` `iostream` `iterator` `limits` `map` `numeric` `regex` `set` `sstream` `string` `tuple`
