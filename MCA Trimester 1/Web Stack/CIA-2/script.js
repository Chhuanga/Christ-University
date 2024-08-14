document.addEventListener('DOMContentLoaded', function() {
    const repoList = document.getElementById('repo-list');

    const xhr = new XMLHttpRequest();
    xhr.open('GET', 'https://api.github.com/users/Chhuanga/repos', true);
    xhr.onload = function() {
        if (this.status === 200) {
            const repos = JSON.parse(this.responseText);
            repos.forEach(repo => {
                // Only display repositories with a description
                if (repo.description) {
                    const li = document.createElement('li');
                    li.className = 'list-group-item';
                    li.innerHTML = `
                        <strong>${repo.name}</strong>: ${repo.description}
                        <br>
                        <a href="${repo.html_url}" target="_blank">View Repository</a>
                    `;
                    repoList.appendChild(li);
                }
            });
        } else {
            repoList.innerHTML = '<li class="list-group-item">Failed to load repositories.</li>';
        }
    };
    xhr.send();
});