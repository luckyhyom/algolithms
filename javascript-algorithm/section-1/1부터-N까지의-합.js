// 자연수 N이 입력되면 1부터 N까지의 합을 출력하는 프로그램을 작성하세요.
function sum(n) {
    let sum = 0;
    for(i=1; i<=n; i++) {
        sum += i;
    }
    return sum;
}