// The “username” field should be non-empty and contain between 6 and 12 characters.
// • The “password” field must be at least 6 characters and should have at least 1 uppercase and 1
// lowercase letters.
// • The user must choose a semester level.
// • The user should not have taken the course COMP 206 before if the semester level is first or second.
// • If the user selects to receive the newsletter, an alert message about potential spam is shown.
// • The user will be notified if the input value for a text field is invalid by turning the label for the
// corresponding field to red, as shown below. When the user focuses on any form element, the red
// label turns back to its original formatting.
var Name = document.getElementById("name");
var password = document.getElementById("password");
var semesterYear = document.getElementById("semester-year");
var comp102 = document.getElementById("comp102");
var comp206 = document.getElementById("comp206");
var math101 = document.getElementById("math101");
var newsletter = document.getElementById("newsletter");
var textarea = document.getElementById("textarea");
var submit = document.getElementById("submit");
function registration() {
    function userNameValidation() {
        var reg = /.{6,12}/;
        if (reg.test(password.value))
            return true;
        return false;
    }
    function PasswordNameValidation() {
        var reg = /(?=.*[A-Z])(?=.*[a-z]).{6,}/;
        if (reg.test(password.value))
            return true;
        return false;
    }
}
submit.addEventListener("click", registration);
