# 📈 IV Calculator (C++) — Implied Volatility Prediction using Black-Scholes Model

This project implements an **Implied Volatility (IV) Calculator** in C++, using both **Newton-Raphson** and **Bisection methods** to estimate the implied volatility of European call/put options based on the **Black-Scholes formula**.

---

## 🚀 Features

- Calculates Implied Volatility from Market Option Price
- Supports both **Call** and **Put** options
- Uses **Newton-Raphson Method** as primary root finder
- **Auto fallback to Bisection Method** if Newton-Raphson fails
- Convergence status and debug logs printed to terminal

---

## 📘 Financial Concepts Used

- **Black-Scholes Pricing Formula**  
  Computes theoretical price of a European option:
  \[
  C = S N(d_1) - K e^{-rT} N(d_2), \quad P = K e^{-rT} N(-d_2) - S N(-d_1)
  \]

- **Implied Volatility**  
  The volatility `σ` that makes the Black-Scholes price equal to the observed market price.

- **Vega**  
  Derivative of BS price w.r.t volatility (used in Newton-Raphson).

---

## 🧠 Root Finding Techniques

- **Newton-Raphson Method**  
  Fast convergence using the Vega derivative  
  \[
  \sigma_{\text{next}} = \sigma - \frac{BS(\sigma) - \text{Market Price}}{\text{Vega}(\sigma)}
  \]

- **Bisection Method**  
  Guaranteed convergence by iteratively narrowing a bracket.

---

## 🛠️ Build Instructions

g++ -std=c++17 src/main.cpp src/black_scholes.cpp src/root_finders.cpp -o ivcalc
./ivcalc


