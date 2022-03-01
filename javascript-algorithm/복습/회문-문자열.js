function solution(str) {
  str = str.toLocaleLowerCase();
  const arr = [...str];
  for (const s of str) {
    if (arr.pop() !== s) return console.log(false);
  }
  return console.log(true);
}
function solution2(str) {
  str = str.toLocaleLowerCase();
  const arr = [...str];
  for (let i = 0; i < str.length; i++) {
    if (str[i] !== str[str.length-1-i]) return console.log(false);
  }
  return console.log(true);
}

solution('dabccbad');
solution2('dabccbad');