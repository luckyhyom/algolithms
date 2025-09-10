### find
find . -maxdepth 1 -type d -newermt "2025-06-01" ! -newermt "2025-07-30" -iname "*Someting*" -exec echo rm -rf {} +

> newerXY (modification, time)
> {} : 출력된 문자열을 담는 공간