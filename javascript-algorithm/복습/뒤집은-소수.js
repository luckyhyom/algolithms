let input = [32, 55, 62, 20, 250, 370, 200, 30, 100];

function flip(nums) {
    let reversedList = [];
    for (let i = 0; i < nums.length; i++) {
        let reversed = 0;
        
        while (nums[i]) {
            let one = nums[i]%10;
            reversed = reversed * 10 + one;
            nums[i] = parseInt(nums[i]/10);
        }

        let flag = true;
        for (let j = 2; j < reversed; j++) {
            if (reversed%i === 0) {
                flag = false
            }
        }

        if (flag && reversed !== 1) {
            reversedList.push(reversed);
        }
    }

    return reversedList;
}

console.log(flip(input));