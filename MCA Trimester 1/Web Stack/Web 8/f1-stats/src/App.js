// src/App.js
import React from 'react';
import Card from './Card';
import './App.css';

const App = () => {
  const cardsData = [
    {
      title: 'Driver 1',
      features: ['Feature 1', 'Feature 2', 'Feature 3'],
      image: 'driver1.jpg',
    },
    {
      title: 'Driver 2',
      features: ['Feature 1', 'Feature 2', 'Feature 3'],
      image: 'driver2.jpg',
    },
    // Add more cards as needed
  ];

  return (
    <div className="App">
      <nav className="navbar">
        <div className="container">
          <a href="#" className="logo">F1 Stats</a>
          <ul className="nav-links">
            <li><a href="#">Home</a></li>
            <li><a href="#">Drivers</a></li>
            <li><a href="#">Teams</a></li>
            <li><a href="#">Races</a></li>
          </ul>
        </div>
      </nav>
      <div className="container">
        <h2>Drivers Championship 2023</h2>
        <div className="cards-container">
          {cardsData.map((card, index) => (
            <Card
              key={index}
              title={card.title}
              features={card.features}
              image={card.image}
            />
          ))}
        </div>
      </div>
    </div>
  );
};

export default App;