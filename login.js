
/* ==================================
   KAAVAL ADMIN LOGIN
   D2 - Frontend Validation
================================== */


// Get HTML elements

const loginForm = document.getElementById("loginForm");

const usernameInput = document.getElementById("username");

const passwordInput = document.getElementById("password");

const togglePassword = document.getElementById("togglePassword");

const loginMessage = document.getElementById("loginMessage");

const currentYear = document.getElementById("currentYear");


// Set current year

if (currentYear) {
    currentYear.textContent = new Date().getFullYear();
}


// Show or hide password

if (togglePassword && passwordInput) {

    togglePassword.addEventListener("click", function () {

        const isPassword =
            passwordInput.type === "password";

        passwordInput.type =
            isPassword ? "text" : "password";

        togglePassword.textContent =
            isPassword ? "Hide" : "Show";

        togglePassword.setAttribute(
            "aria-label",
            isPassword ? "Hide password" : "Show password"
        );

    });

}


// Display message

function showMessage(message, type) {

    loginMessage.textContent = message;

    loginMessage.className =
        "login-message show " + type;

}


// Login form validation

if (loginForm) {

    loginForm.addEventListener("submit", function (event) {

        event.preventDefault();

        const username = usernameInput.value.trim();

        const password = passwordInput.value;

        // Check empty username

        if (!username) {

            showMessage(
                "Please enter your username.",
                "error"
            );

            usernameInput.focus();

            return;
        }


        // Check empty password

        if (!password) {

            showMessage(
                "Please enter your password.",
                "error"
            );

            passwordInput.focus();

            return;
        }


        // UI-only status

        showMessage(
            "Form validation successful. Backend authentication is not connected yet. No login request was sent.",
            "info"
        );

    });

}


console.log("KAAVAL Login UI loaded successfully.");

