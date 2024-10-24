// src/Drivers.js
import React, { useState, useEffect } from 'react';
import axios from 'axios';

function Drivers() {
  const [drivers, setDrivers] = useState([]);

  useEffect(() => {
    const fetchDrivers = async () => {
      try {
        const response = await axios.get('https://api.openf1.org/v1/drivers');
        setDrivers(response.data);
      } catch (error) {
        console.error('Error fetching drivers:', error);
      }
    };

    fetchDrivers();
  }, []);

  return (
    <div className="drivers">
      <h1>F1 Drivers</h1>
      <ul>
        {drivers.map((driver) => (
          <li key={driver.id}>
            {driver.firstName} {driver.lastName}
          </li>
        ))}
      </ul>
    </div>
  );
}

export default Drivers;