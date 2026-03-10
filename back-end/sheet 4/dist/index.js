"use strict";
// Write a TypeScript program that changes the text color to plum and adds a magenta
// dashed border around emphasized words in a paragraph when the mouse moves over the
// paragraph. The paragraph should return to its original formatting when the mouse moves
// out of the paragraph. The provided figures illustrate the functionality of the program.
let myem = document.querySelectorAll("#paragraph>em");
let mypara = document.querySelector("#paragraph");
mypara.addEventListener("mouseover", () => {
    for (let i = 0; i < myem.length; i++) {
        let myElement = myem[i];
        if (myElement) {
            myElement.style.cssText = `
    color: plum;
    border: 1px dashed magenta;
    `;
        }
    }
});
mypara.addEventListener("mouseout", () => {
    for (let i = 0; i < myem.length; i++) {
        let myElement = myem[i];
        if (myElement) {
            myElement.style.cssText = "";
        }
    }
});
//--------------------------------------
let options = document.querySelectorAll(".option");
let inputs = document.querySelectorAll("input");
for (let i = 0; i < inputs.length; i++) {
    let myinput = inputs[i];
    myinput.addEventListener("change", () => {
        let myoption = options[0];
        for (let j = 0; j < options.length; j++) {
            let current = options[j];
            if (current.value == myinput.id)
                myoption = current;
        }
        if (myoption.style.display != "none") {
            myoption.style.display = "none";
        }
        else {
            myoption.style.display = "block";
        }
    });
}
//--------------------------------------
// Write a TypeScript program that stores entries from text fields into an array of
// “Student” objects when the user clicks the “Add Student” button. Each student
// object in the array should have properties for name, age, and GPA. The program
// should provide a drop-down list to select the sorting order: descending order by GPA
// or ascending order by name. The program should display the sorted results in a text
// area. In addition, if the number of students with a GPA less than 2 exceeds 3, then an
// alert message should be displayed. The form design is shown in the provided figure.
// Note: Use the “change” event on the <select> HTML tag for handling the
// sorting order choice.
let name1 = document.getElementById("name");
let age1 = document.getElementById("age");
let gpa1 = document.getElementById("gpa");
let addbtn = document.getElementById("add");
let select = document.getElementById("li");
let display = document.getElementById("display");
let students = [];
addbtn.addEventListener("click", () => {
    let student = {
        name: name1.value,
        age: parseInt(age1.value),
        gpa: parseFloat(gpa1.value),
    };
    name1.value = "";
    age1.value = "";
    gpa1.value = "";
    if (student.name == "")
        return
    students.push(student);
});
select.addEventListener("change", () => {
    if (select.value == "gpa") {
        students.sort((a, b) => b.gpa - a.gpa);
        display.innerHTML = "";
        for (let i = 0; i < students.length; i++) {
            let tr = document.createElement("tr");
            let td1 = document.createElement("td");
            let td2 = document.createElement("td");
            let td3 = document.createElement("td");
            let tdname = students[i]?.name;
            let tdgpa = students[i]?.gpa;
            let tdage = students[i]?.age;
            td1.innerText = tdname;
            td2.innerText = tdgpa.toString();
            td3.innerText = tdage.toString();
            tr.appendChild(td1);
            tr.appendChild(td2);
            tr.appendChild(td3);
            display.appendChild(tr);
        }
    }
    if (select.value == "name") {
        students.sort((a, b) => {
            if (a.name < b.name)
                return -1;
            if (a.name > b.name)
                return 1;
            if (a.age < b.age)
                return -1;
            if (a.age > b.age)
                return 1;
            return 0;
        });
        display.innerHTML = "";
        for (let i = 0; i < students.length; i++) {
            let tr = document.createElement("tr");
            let td1 = document.createElement("td");
            let td2 = document.createElement("td");
            let td3 = document.createElement("td");
            let tdname = students[i]?.name;
            let tdgpa = students[i]?.gpa;
            let tdage = students[i]?.age;
            td1.innerText = tdname;
            td2.innerText = tdgpa.toString();
            td3.innerText = tdage.toString();
            tr.appendChild(td1);
            tr.appendChild(td2);
            tr.appendChild(td3);
            display.appendChild(tr);
        }
    }
});
