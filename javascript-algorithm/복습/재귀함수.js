function solution(n) {
  function func(x) {
    if (x === 0)  {
      return;
    } else {
      func(x-1);
      console.log(x);
    }
  }
  func(n);
}

solution(10);