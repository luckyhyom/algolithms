function bigger(nums) {
    let result = []
    return nums.filter((num, i) => {
        if(i===0) return true;
        return num > nums[i-1]
    })
};

console.log(bigger([7, 3, 9, 5, 6, 12]));