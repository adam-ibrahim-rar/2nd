let myarr = [5, 2, 3, 4, 5, 9, 8]
function smallerThan(array: number[], el: number) {
    let newarr: number[] = []
    for (let index = 0; index < array.length; index++) {
        // array[index]<el ? newarr.push(array[index]):continue
        if (array[index] < el) {
            newarr.push(array[index])
        }
        else continue
    }
    return newarr
}
// --------------------------------------------------
interface user {
    name: string
    age: number
    isActive: boolean
}
function getActiveUsers(users: user[]): user[] {
    let activeUsers: user[] = []
    for (let i = 0; i < users.length; i++) {
        if (users[i].isActive === true) {
            activeUsers.push(users[i])
        } else continue
    }
    return activeUsers;
}

function prineActiveUsers(users: user[]): string {
    return getActiveUsers(users).toString()
}
// --------------------------------------------------
function greaterThan(array: number[], num: number): number[] {
    let newarr: number[] = []
    let i = 0
    while (array.length > 1) {
        let myelment = array.find(el => el > num)
        if (myelment) {
            newarr.push(myelment)
            array.slice(i)
        }
    }
    return newarr
}
let myarra = [4, 5, 6, 7, 9]
console.log(greaterThan(myarra, 6))
// --------------------------------------------------------
let arr: number[] = [1,2,2,3,4,4,4,5,5,5,5,6]
function dothing(array: number[]) {
  array.sort((a, b) => a - b);
  let newarr: number[] = [];
  let count;

  for (let i = 0; i < array.length; i++) {
    count = 0;
    let element = array[i];

    for (let j = 0; j < array.length; j++) {
      if (array[i] == array[j]) {
        count++;
        if (element)
             i = array.lastIndexOf(element);
      }
    }
    if (count < 3) {
      if (element) newarr.push(element);
    }
  }
  return newarr;
}
console.log(dothing(arr));
// --------------------------------------------------------
type priority = "high" | "medium" | "low"
interface task {
    id: number
    description: string
    priority: priority
}
class taskmanger {
    tasks: task[]
    constructor(tasks: task[]
    ) {
        this.tasks = tasks
    }
    getHighPriortyTasks(): task[] {
        let HighPriortyTasks: task[] = []
        for (let i = 0; i < this.tasks.length; i++) {
            if (this.tasks[i].priority === "high") {
                HighPriortyTasks.push(this.tasks[i])
            }
        }
        return HighPriortyTasks
    }
    completedTasks(id: number): task[] {
        let completedTasks: task[] = []
        for (let i = 0; i < this.tasks.length; i++) {
            if (this.tasks[i].id != id) {
                completedTasks.push(this.tasks[i])
            }
        }
        return completedTasks
    }
    sortTaskByPriorty(): task[] {
        let sortedTasks = this.tasks
        const priorityOrder = {
            high: 1,
            medium: 2,
            low: 3
        }
        sortedTasks.sort((a, b) => priorityOrder[a.priority] - priorityOrder[b.priority])
        return sortedTasks
    }
}
let tasks: task[] = [
    {
        id: 1,
        priority: "high",
        description: "kkk"
    }, {
        id: 2,
        priority: "high",
        description: "kkk"
    }, {
        id: 36,
        priority: "medium",
        description: "kkk"
    }, {
        id: 5,
        priority: "high",
        description: "kkk"
    }, {
        id: 56,
        priority: "low",
        description: "kkk"
    },
]
let MYtasks = new taskmanger(tasks)
// console.log(MYtasks.sortTaskByPriorty())