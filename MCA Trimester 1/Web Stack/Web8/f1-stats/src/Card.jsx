// src/Card.jsx
import React, { useState } from 'react';
import './Card.css';

const Card = ({ driver, team, points, driverImage, driverUrl, teamUrl }) => {
  const [liked, setLiked] = useState(false);

  const toggleLike = () => {
    setLiked(!liked);
  };

  const handleImageClick = () => {
    window.open(driverUrl, '_blank');
  };

  return (
    <div className="card">
      <div className={`like-icon ${liked ? 'liked' : ''}`} onClick={toggleLike}>
        <svg
          xmlns="http://www.w3.org/2000/svg"
          viewBox="0 0 24 24"
          fill={liked ? "red" : "none"}
          stroke="currentColor"
          strokeWidth="2"
          strokeLinecap="round"
          strokeLinejoin="round"
          className="feather feather-heart"
        >
          <path d="M20.84 4.61a5.5 5.5 0 0 0-7.78 0L12 5.67l-1.06-1.06a5.5 5.5 0 0 0-7.78 7.78l1.06 1.06L12 21.23l7.78-7.78 1.06-1.06a5.5 5.5 0 0 0 0-7.78z"></path>
        </svg>
      </div>
      <img src={driverImage} alt={driver} className="card-image" onClick={handleImageClick} />
      <h3>{driver}</h3>
      <p>Team: <a href={teamUrl} target="_blank" rel="noopener noreferrer">{team}</a></p>
      <p>Points: {points}</p>
    </div>
  );
};

export default Card;