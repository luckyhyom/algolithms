function mySolution(arr, target) {
    const targetMap = new Map();
    for (const s of target) {
        if (targetMap.has(s)) {
            targetMap.set(s, targetMap.get(s) + 1);
        } else {
            targetMap.set(s, 1);
        }
    }

    const arrMap = new Map();
    let count = 0;
    for (const s of arr) {
        if (count === target.length) {
            break;
        }
        
        if (arrMap.has(s)) {
            arrMap.set(s, arrMap.get(s) + 1);
        } else {
            arrMap.set(s, 1);
        }
        count += 1;
    }

    let answer = 1;
    for (const [key, value] of targetMap) {
        if (targetMap.get(key) !== arrMap.get(key)) {
            answer = 0;
        }
    }

    const j = target.length;
    for (let i = j; i < arr.length; i++) {
        const left = arr[i - j]
        const right = arr[i];
        arrMap.set(left, arrMap.get(left) - 1);
        if (arrMap.has(right)) {
            arrMap.set(right, arrMap.get(right) + 1);
        } else {
            arrMap.set(right, 1);
        }
        let count = 0;
        for (const [key, value] of targetMap) {
            if (targetMap.get(key) !== arrMap.get(key)) {
                break;
            };
            count++;
        }
        if (count === target.length) {
            answer++;
        }
    }
    return answer;
}

console.log(mySolution('bacaAacba','abc'));