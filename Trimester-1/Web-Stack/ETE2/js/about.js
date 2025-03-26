document.addEventListener('DOMContentLoaded', function () {
    const teamMembers = [
        {
            name: "John Doe",
            role: "Founder & CEO",
            imageUrl: "https://images.pexels.com/photos/1681010/pexels-photo-1681010.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=1"
        },
        {
            name: "Jane Smith",
            role: "Chief Veterinarian",
            imageUrl: "https://images.pexels.com/photos/762020/pexels-photo-762020.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=1"
        },
        {
            name: "Emily Johnson",
            role: "Dog Trainer",
            imageUrl: "https://images.pexels.com/photos/1065084/pexels-photo-1065084.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=1"
        }
    ];

    const teamMembersContainer = document.getElementById('teamMembers');

    teamMembers.forEach(member => {
        const memberDiv = document.createElement('div');
        memberDiv.classList.add('team-member');

        memberDiv.innerHTML = `
            <img src="${member.imageUrl}" alt="${member.name}">
            <h3>${member.name}</h3>
            <p>${member.role}</p>
        `;

        teamMembersContainer.appendChild(memberDiv);
    });
});