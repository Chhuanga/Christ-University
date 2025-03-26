document.addEventListener('DOMContentLoaded', function () {
    const fetchButton = document.getElementById('fetchButton');
    const dogImage = document.getElementById('dogImage');

    fetchButton.addEventListener('click', fetchRandomDogImage);

    function fetchRandomDogImage() {
        fetch('https://dog.ceo/api/breeds/image/random')
            .then(response => response.json())
            .then(data => {
                dogImage.src = data.message;
            })
            .catch(error => {
                console.error('Error fetching the dog image:', error);
            });
    }

    
    fetchRandomDogImage();//fetching image on page load
});
