document.addEventListener('DOMContentLoaded', function () {
    const statsContainer = document.getElementById('stats-container');
    const searchInput = document.getElementById('search');
    const sortSelect = document.getElementById('sort');
    const prevButton = document.getElementById('prev');
    const nextButton = document.getElementById('next');
    const pageInfo = document.getElementById('page-info');
    const errorMessage = document.getElementById('error-message');

    let driversChampionship = [];
    let currentPage = 1;
    const itemsPerPage = 5;

    function fetchStats() {
        fetch('f1stats.json')
            .then(response => {
                if (!response.ok) {
                    throw new Error('Network response was not ok ' + response.statusText);
                }
                return response.json();
            })
            .then(data => {
                console.log('Fetched data:', data); // Debugging statement
                driversChampionship = data.drivers_championship;
                if (!Array.isArray(driversChampionship)) {
                    throw new Error('Fetched data is not an array');
                }
                displayStats();
            })
            .catch(error => {
                errorMessage.textContent = 'Error fetching data: ' + error;
                console.error('Error fetching data:', error); // Debugging statement
            });
    }

    function displayStats() {
        const filteredStats = filterStats(driversChampionship);
        const sortedStats = sortStats(filteredStats);
        const paginatedStats = paginateStats(sortedStats);

        statsContainer.innerHTML = '';
        paginatedStats.forEach(stat => {
            const statCard = document.createElement('div');
            statCard.classList.add('stat-card');
            statCard.innerHTML = `
                <h2>${stat.driver}</h2>
                <p>Position: ${stat.position}</p>
                <p>Team: ${stat.team}</p>
                <p>Points: ${stat.points}</p>
                <a href="${stat.driver_url}" target="_blank">
                    <img src="${stat.driver_image}" alt="${stat.driver}" class="driver-image">
                </a>
            `;
            statsContainer.appendChild(statCard);
        });

        pageInfo.textContent = `Page ${currentPage} of ${Math.ceil(filteredStats.length / itemsPerPage)}`;
    }

    function filterStats(stats) {
        const searchTerm = searchInput.value.toLowerCase();
        return stats.filter(stat => stat.driver.toLowerCase().includes(searchTerm));
    }

    function sortStats(stats) {
        const sortBy = sortSelect.value;
        return stats.sort((a, b) => {
            if (sortBy === 'name') {
                return a.driver.localeCompare(b.driver);
            } else if (sortBy === 'points') {
                return b.points - a.points;
            }
        });
    }

    function paginateStats(stats) {
        const startIndex = (currentPage - 1) * itemsPerPage;
        return stats.slice(startIndex, startIndex + itemsPerPage);
    }

    searchInput.addEventListener('input', displayStats);
    sortSelect.addEventListener('change', displayStats);
    prevButton.addEventListener('click', () => {
        if (currentPage > 1) {
            currentPage--;
            displayStats();
        }
    });
    nextButton.addEventListener('click', () => {
        if (currentPage < Math.ceil(filterStats(driversChampionship).length / itemsPerPage)) {
            currentPage++;
            displayStats();
        }
    });

    fetchStats();
});