let input = [128, 460, 603, 40, 521, 137, 123];

function sum(nums) {
    let result = 0;
    let max = 0;
    for (let num of nums) {
        let x = num;
        let temp = 0;
        while (x) {
            temp += x%10;
            x = Math.floor(x/10);
        }
        if (max === temp) {
            result = Math.max(result, num);
        } else {
            max = Math.max(max, temp);
        }
        if (max === temp) {
            result = num;
        }
    }
    return result;
}

console.log(sum(input));