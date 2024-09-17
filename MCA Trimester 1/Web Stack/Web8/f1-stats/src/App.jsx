// src/App.js
import React, { useEffect, useState } from 'react';
import Card from './Card.jsx'; // Update the import statement
import './App.css';
import f1stats from './f1stats.json';

const App = () => {
  const [drivers, setDrivers] = useState([]);

  useEffect(() => {
    // Simulate fetching data from f1stats.json
    setDrivers(f1stats.drivers_championship);
  }, []);

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
          {drivers.map((driver, index) => (
            <Card
              key={index}
              driver={driver.driver}
              team={driver.team}
              points={driver.points}
              driverImage={driver.driver_image}
              driverUrl={driver.driver_url}
              teamUrl={driver.team_url}
            />
          ))}
        </div>
      </div>
    </div>
  );
};

export default App;