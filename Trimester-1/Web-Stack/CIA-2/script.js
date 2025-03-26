document.addEventListener('DOMContentLoaded', function() {
    const repoList = document.getElementById('repo-list');

    const xhr = new XMLHttpRequest();
    xhr.open('GET', 'https://api.github.com/users/Chhuanga/repos', true);
    xhr.onload = function() {
        if (this.status === 200) {
            const repos = JSON.parse(this.responseText);
            console.log('API Response:', repos); // Log the API response to the console
            repos.forEach(repo => {
                const li = document.createElement('li');
                li.className = 'list-group-item';
                li.innerHTML = `
                    <strong>${repo.name}</strong>: ${repo.description ? repo.description : 'No description available'}
                    <br>
                    <a href="${repo.html_url}" target="_blank">View Repository</a>
                `;
                repoList.appendChild(li);
            });
        } else {
            console.error('Failed to load repositories. Status:', this.status);
            repoList.innerHTML = '<li class="list-group-item">Failed to load repositories.</li>';
        }
    };
    xhr.onerror = function() {
        console.error('Request error');
        repoList.innerHTML = '<li class="list-group-item">Failed to load repositories due to a network error.</li>';
    };
    xhr.send();
});