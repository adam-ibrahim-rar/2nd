"use strict";
// The “username” field should be non-empty and contain between 6 and 12 characters.
// • The “password” field must be at least 6 characters and should have at least 1 uppercase and 1
// lowercase letters.
// • The user must choose a semester level.
// • The user should not have taken the course COMP 206 before if the semester level is first or second.
// • If the user selects to receive the newsletter, an alert message about potential spam is shown.
// • The user will be notified if the input value for a text field is invalid by turning the label for the
// corresponding field to red, as shown below. When the user focuses on any form element, the red
// label turns back to its original formatting.
let Name = document.getElementById("name");
let password = document.getElementById("password");
let semesterYear = document.getElementById("semester-year");
let comp206 = document.getElementById("comp206");
let courses = document.getElementsByClassName("courses");
let newsletter = document.getElementById("newsletter");
let textarea = document.getElementById("textarea");
let Submit = document.getElementById("submit");
let lable = document.querySelectorAll(".lable");
let inputs = document.querySelectorAll("input");
function registration() {
    for (let i = 0; i < inputs.length - 2; i++) {
        let myinput = inputs[i];
        function resetColor() {
            for (let i = 0; i < 3; i++) {
                let mylab = lable[i];
                mylab.style.color = "";
            }
        }
        myinput.addEventListener("change", resetColor);
        myinput.addEventListener("focus", resetColor);
    }
    function userNameValidation() {
        let reg = /.{6,12}/;
        if (reg.test(password.value))
            return true;
        return false;
    }
    function PasswordNameValidation() {
        let reg = /(?=.*[A-Z])(?=.*[a-z]).{6,}/;
        if (reg.test(password.value))
            return true;
        return false;
    }
    function semsterlevelValidation() {
        if (semesterYear.value == "" ||
            semesterYear.value == "select your semester year") {
            return false;
        }
        if (semesterYear.value == "1" || semesterYear.value == "2") {
            if (comp206.checked == true) {
                return false;
            }
            return true;
        }
        return true;
    }
    let mycourses = [];
    for (let i = 0; i < courses.length; i++) {
        let course = courses[i];
        if (course.checked == true)
            mycourses.push(course.name);
    }
    if (!userNameValidation() ||
        !PasswordNameValidation() ||
        !semsterlevelValidation()) {
        for (let i = 0; i < 3; i++) {
            let mylab = lable[i];
            mylab.style.color = "red";
        }
        textarea.style.display = "none";
    }
    else {
        textarea.style.display = "block";
        textarea.innerHTML = `
      user name is : ${Name.value} <br>
      password is : ${password.value} <br>
      semster-Year is : ${semesterYear.value} <br>
      courses taken : ${mycourses.join(",")}
      `;
        if (newsletter.checked == true) {
            window.alert("potential spam is shown");
        }
        function confirm() {
            let conf = window.confirm("do you want to submit ?");
            if (conf) {
                let newWindo = window.open("massage.html");
            }
        }
        textarea.addEventListener("click", confirm);
        textarea.addEventListener("mouseover", confirm);
    }
}
Submit.addEventListener("click", registration);
