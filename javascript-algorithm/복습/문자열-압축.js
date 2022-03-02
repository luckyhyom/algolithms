function solution(str) {
  const map = new Map();
  for (const s of str) {
    map.set(s, map.get(s) === undefined ? 1 : map.get(s) + 1);
  }
  let result = '';
  for (const [key, value] of map) {
    result += key;
    result += value > 1 ? value : '';
  }

  return result;
}

console.log(solution('KKHSSSSSSSE'));