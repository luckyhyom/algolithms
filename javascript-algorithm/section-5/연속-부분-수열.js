let input = [1,2,1,3,1,1,1,2];
let input2 = 6;
let result = 3;

function solution(arr, k) {
    let count = 0;
    for (let i = 0; i < arr.length; i++) {
        sum = 0;
        for (let j = i; j < arr.length; j++) {
            sum += arr[j]
            if (sum === k) count++;
        }
    }
    return count;
}

function solution2(arr, k) {
    let L = 0;
    let R = 0;
    let sum = 0;
    let count = 0;
    while (R < arr.length) {
        if (sum === k) {
            sum -= arr[L++];
            count++;
        } else if (sum < k) {
            sum += arr[R++];
        } else {
            sum -= arr[L++];
        }
    }

    return count;
}

// console.log(solution2(input,6));


const review = (arr, k) => {
    let sum = 0;
    let count = 0;
    let left = 0;
    let right = 0;

    for (let i = 0; i < arr.length; i++) {
        sum += arr[right++];
        if (sum === k) {
            count++;
            sum -= arr[left++];
        }

        if (sum > k) {
            sum -= arr[left++];
            if (sum === k) {
                count++;
                sum -= arr[left++];
            }
        }
    }

    return [count, sum];
}

console.log(review(input,input2));


function _solution(m, arr){
    let answer=0, lt=0, sum=0;
    for(let rt=0; rt<arr.length; rt++){
        sum+=arr[rt];
        if(sum===m) answer++;

        // 세탁기 (반복문과 if역할까지)
        while(sum>=m){
            sum-=arr[lt++];
            if(sum===m) answer++;       
        }
    }        
    return answer;
}