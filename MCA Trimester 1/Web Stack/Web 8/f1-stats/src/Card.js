// src/Card.js
import React, { useState } from 'react';
import './Card.css';

const Card = ({ title, features, image }) => {
  const [liked, setLiked] = useState(false);

  const toggleLike = () => {
    setLiked(!liked);
  };

  return (
    <div className="card">
      <img src={image} alt={title} className="card-image" />
      <h3>{title}</h3>
      <ul>
        {features.map((feature, index) => (
          <li key={index}>{feature}</li>
        ))}
      </ul>
      <div className={`like-icon ${liked ? 'liked' : ''}`} onClick={toggleLike}>
        ❤️
      </div>
    </div>
  );
};

export default Card;