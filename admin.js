
/*
 * KAAVAL ADMIN DASHBOARD
 * D1 - Basic JavaScript Functions
 */

// Set current year
const yearElement = document.getElementById("year");

if (yearElement) {
    yearElement.textContent = new Date().getFullYear();
}


// India clock
function updateClock() {
    const clockElement = document.getElementById("clock");

    if (!clockElement) {
        return;
    }

    const now = new Date();

    clockElement.textContent = new Intl.DateTimeFormat("en-IN", {
        timeZone: "Asia/Kolkata",
        hour: "2-digit",
        minute: "2-digit",
        second: "2-digit",
        hour12: true
    }).format(now);
}

updateClock();
setInterval(updateClock, 1000);


// Mobile sidebar
const menuButton = document.getElementById("menuButton");
const sidebar = document.getElementById("sidebar");

if (menuButton && sidebar) {

    menuButton.addEventListener("click", function () {

        const isOpen = sidebar.classList.toggle("is-open");

        menuButton.setAttribute(
            "aria-expanded",
            String(isOpen)
        );

    });

}


// Navigation active state
const navLinks = document.querySelectorAll(".nav-link");

function updateActiveLink() {

    const currentHash = window.location.hash || "#overview";

    navLinks.forEach(function (link) {

        if (link.getAttribute("href") === currentHash) {
            link.classList.add("active");
        } else {
            link.classList.remove("active");
        }

    });
}

window.addEventListener("hashchange", updateActiveLink);

updateActiveLink();


// Close mobile sidebar after selecting a section
navLinks.forEach(function (link) {

    link.addEventListener("click", function () {

        if (sidebar && menuButton) {
            sidebar.classList.remove("is-open");
            menuButton.setAttribute("aria-expanded", "false");
        }

    });

});


console.log("KAAVAL Admin Dashboard D1 loaded successfully.");
