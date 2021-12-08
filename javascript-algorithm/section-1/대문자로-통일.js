function toUpper(str) {
    return str.toUpperCase();
}

function toUpper2(str) {
    let answer = '';
    for (const s of str) {
        if (s === s.toLowerCase()) {
            answer += s.toUpperCase();
        } else {
            answer += s;
        }
    }

    return answer;
}
