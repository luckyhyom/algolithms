function flip(nums) {
    let result = [];
    // 2나 3으로 나눠떨어지지 않는 수???
    // 나누는 수가 몫보다 커지기 전까지
    for (const n of nums) {
        let reversed = parseInt(String(n).split('').reverse().join(''));
        let flag = true;
        for (let i = 2; i < reversed; i++) {
            if (reversed === 1 || reversed%i === 0) {
                flag=false
                break;
            }
        }
        if (flag && reversed !== 1) {
            result.push(reversed);
        }
    }
    return result;
}

function flip2(nums) {
    let result = [];
    function isPrime(n) {
        if (n === 1) return false;
        for (let i = 2; i < Math.sqrt(n); i++) {
            if (n%i === 0) return false;
        }
        return true;
    }
    for (let n of nums) {
        let reversed = 0;
        while (n) {
            reversed = reversed*10+(n%10);
            n = parseInt(n/10);
        }

        if (isPrime(reversed)) result.push(reversed);
    }
    return result;
}

console.log(flip2([32, 55, 62, 20, 250, 370, 200, 30, 100]));