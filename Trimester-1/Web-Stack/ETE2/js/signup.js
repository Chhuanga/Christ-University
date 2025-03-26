document.addEventListener('DOMContentLoaded', function () {
    // Get references to form elements
    const signupForm = document.getElementById('signupForm');
    const nameInput = document.getElementById('name');
    const emailInput = document.getElementById('email');
    const passwordInput = document.getElementById('password');
    const confirmPasswordInput = document.getElementById('confirmPassword');
    const dogLoverInput = document.getElementById('dogLover');

    // Get references to feedback elements
    const nameFeedback = document.getElementById('nameFeedback');
    const emailFeedback = document.getElementById('emailFeedback');
    const passwordFeedback = document.getElementById('passwordFeedback');
    const confirmPasswordFeedback = document.getElementById('confirmPasswordFeedback');
    const passwordMatchFeedback = document.getElementById('passwordMatchFeedback');
    const dogLoverFeedback = document.getElementById('dogLoverFeedback');

    // Add event listeners for input validation
    nameInput.addEventListener('input', function () {
        validateName();
    });

    emailInput.addEventListener('input', function () {
        validateEmail();
    });

    passwordInput.addEventListener('input', function () {
        validatePassword();
    });

    passwordInput.addEventListener('blur', function () {
        validatePassword();
    });

    confirmPasswordInput.addEventListener('input', function () {
        validateConfirmPassword();
    });

    confirmPasswordInput.addEventListener('blur', function () {
        validateConfirmPassword();
    });

    dogLoverInput.addEventListener('change', function () {
        validateDogLover();
    });

    // Add event listener for form submission
    signupForm.addEventListener('submit', function (event) {
        event.preventDefault();

        // Validate the form before submission
        if (validateForm()) {
            alert('Sign up successful!');
            signupForm.reset();
            resetFeedback();
        }
    });

    // Validate the name input
    function validateName() {
        if (nameInput.value.trim() === '') {
            nameFeedback.textContent = '✖';
            nameFeedback.classList.add('invalid');
            nameFeedback.classList.remove('valid');
            return false;
        } else {
            nameFeedback.textContent = '✔';
            nameFeedback.classList.add('valid');
            nameFeedback.classList.remove('invalid');
            return true;
        }
    }

    // Validate the email input
    function validateEmail() {
        const emailPattern = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
        if (!emailPattern.test(emailInput.value)) {
            emailFeedback.textContent = '✖';
            emailFeedback.classList.add('invalid');
            emailFeedback.classList.remove('valid');
            return false;
        } else {
            emailFeedback.textContent = '✔';
            emailFeedback.classList.add('valid');
            emailFeedback.classList.remove('invalid');
            return true;
        }
    }

    // Validate the password input
    function validatePassword() {
        if (passwordInput.value.length < 6) {
            passwordFeedback.textContent = '✖';
            passwordFeedback.classList.add('invalid');
            passwordFeedback.classList.remove('valid');
            return false;
        } else {
            passwordFeedback.textContent = '✔';
            passwordFeedback.classList.add('valid');
            passwordFeedback.classList.remove('invalid');
            return true;
        }
    }

    // Validate the confirm password input
    function validateConfirmPassword() {
        if (confirmPasswordInput.value !== passwordInput.value) {
            confirmPasswordFeedback.textContent = '✖';
            confirmPasswordFeedback.classList.add('invalid');
            confirmPasswordFeedback.classList.remove('valid');
            passwordMatchFeedback.textContent = 'Passwords do not match';
            passwordMatchFeedback.classList.add('invalid');
            passwordMatchFeedback.classList.remove('valid');
            return false;
        } else {
            confirmPasswordFeedback.textContent = '✔';
            confirmPasswordFeedback.classList.add('valid');
            confirmPasswordFeedback.classList.remove('invalid');
            passwordMatchFeedback.textContent = 'Passwords match';
            passwordMatchFeedback.classList.add('valid');
            passwordMatchFeedback.classList.remove('invalid');
            return true;
        }
    }

    // Validate the dog lover checkbox
    function validateDogLover() {
        if (!dogLoverInput.checked) {
            dogLoverFeedback.textContent = '✖';
            dogLoverFeedback.classList.add('invalid');
            dogLoverFeedback.classList.remove('valid');
            return false;
        } else {
            dogLoverFeedback.textContent = '✔';
            dogLoverFeedback.classList.add('valid');
            dogLoverFeedback.classList.remove('invalid');
            return true;
        }
    }

    // Validate the entire form
    function validateForm() {
        const isNameValid = validateName();
        const isEmailValid = validateEmail();
        const isPasswordValid = validatePassword();
        const isConfirmPasswordValid = validateConfirmPassword();
        const isDogLoverValid = validateDogLover();

        return isNameValid && isEmailValid && isPasswordValid && isConfirmPasswordValid && isDogLoverValid;
    }

    // Reset feedback messages
    function resetFeedback() {
        nameFeedback.textContent = '';
        emailFeedback.textContent = '';
        passwordFeedback.textContent = '';
        confirmPasswordFeedback.textContent = '';
        passwordMatchFeedback.textContent = '';
        dogLoverFeedback.textContent = '';
    }
});