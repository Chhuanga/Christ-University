document.addEventListener('DOMContentLoaded', function () {
    // Get the container element where the breed information will be displayed
    const breedsContainer = document.getElementById('breedsContainer');

    // Fetch the JSON data from the provided URL
    fetch('https://raw.githubusercontent.com/Chhuanga/WebETE/main/breeds.json')
        .then(response => {
            // Convert the response to JSON format
            return response.json();
        })
        .then(breeds => {
            // Iterates over each breed in the JSON data
            breeds.forEach(breed => {
                // Create a new div element for each breed
                const breedDiv = document.createElement('div');
                breedDiv.classList.add('breed');

                // Set the inner HTML of the div with the breed information
                breedDiv.innerHTML = `
                    <img src="${breed.imageUrl}" alt="${breed.breedName}">
                    <h2>${breed.breedName}</h2>
                    <p>${breed.description}</p>
                    <ul>
                        <li><strong>Size:</strong> ${breed.size}</li>
                        <li><strong>Lifespan:</strong> ${breed.lifespan}</li>
                        <li><strong>Origin:</strong> ${breed.origin}</li>
                    </ul>
                `;

                // Append the breed div to the container
                breedsContainer.appendChild(breedDiv);
            });
        })
        .catch(error => {
            // Log any errors that occur during the fetch operation
            console.error('Error fetching the breeds data:', error);
        });
});