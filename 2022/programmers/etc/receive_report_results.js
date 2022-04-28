function solution(id_list, report, k) {
    var answer = [];
    // users -> id : set[frodo, neo];
    let users = {};
    // reports -> id: 신고 횟수
    let reports = {};

    id_list.forEach((user)=>{
        users[user] = new Set();
        reports[user] = 0;
    })
    report.forEach((repo)=>{
        const [reporting, reported] = repo.split(" ");
        users[reporting].add(reported);
    })
    Object.keys(users).map((key)=>{
        users[key].forEach((reportedUser)=>{
            reports[reportedUser]++;
        })
    })
   
    id_list.forEach((user)=>{
        let count = 0;
        users[user].forEach((reportedUser)=>{
            if(reports[reportedUser] >= k) count++;
        })
        answer.push(count);
    })
    
    return answer;
}