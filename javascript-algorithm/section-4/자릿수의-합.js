let input = [128, 460, 603, 40, 521, 137, 123];

function sum(arr) {
    let max = 0;
    let maxIndex = 0;
    arr.forEach((n, i) => {
        let str = String(n);
        let sum = str.split('').reduce((pre, cur) => {
            return pre + parseInt(cur);
        })
        if (sum > max) {
            max = sum;
            maxIndex = i;
        }
        if (sum === max) {
            if (arr[i] > arr[maxIndex]) {
                max = sum;
                maxIndex = i;
            }
        }
    });

    return arr[maxIndex];
}


function sum2(nums) {
    let max = 0;
    let origin = 0;
    for (let i = 0; i < nums.length; i++) {
        let copy = nums[i];
        let sum = 0;
        while (copy) {
            sum += copy%10;
            copy = Math.floor(copy/10);
        }

        if (sum>max) {
            max = sum;
            origin = nums[i];
        }
        else if (sum===max) {
            if (nums[i] > origin) {
                origin = nums[i];
            }
        }
    }
    return origin;
}

console.log(sum2(input));

