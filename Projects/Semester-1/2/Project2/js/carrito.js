document.addEventListener('DOMContentLoaded', () => {
  const listaCarrito = document.getElementById('lista-carrito');
  const resumenCarrito = document.getElementById('resumen-carrito');
  const botonVaciar = document.getElementById('vaciar-carrito');

  function renderizarCarrito() {
    const carrito = JSON.parse(localStorage.getItem('carrito')) || [];
    listaCarrito.innerHTML = '';

    let total = 0;
    carrito.forEach((producto, index) => {
      total += producto.precio * producto.cantidad;
      const item = document.createElement('article');
      item.className = 'producto-carrito';
      item.innerHTML = `
        <div class="info-producto">
          <h4>${producto.nombre}</h4>
          <p>$${producto.precio} x ${producto.cantidad}</p>
        </div>
        <button class="eliminar-producto" data-index="${index}">Eliminar</button>
      `;
      listaCarrito.appendChild(item);
    });

    const envio = total > 0 ? (total >= 100 ? 0 : 5) : 0;
    const resumen = `
      <h3>Resumen</h3>
      <p>Productos: ${carrito.length}</p>
      <p>Envío: ${envio === 0 ? 'Gratis' : `$${envio.toFixed(2)}`}</p>
      <p class="total">Total: $${(total + envio).toFixed(2)}</p>
      <div class="metodos-pago">
        <h4>Métodos de pago</h4>
        <img src="assets/img/visa.svg" alt="Visa">
        <img src="assets/img/mastercard.png" alt="Mastercard">
        <img src="assets/img/paypal.webp" alt="PayPal">
      </div>
    `;
    resumenCarrito.innerHTML = resumen;

    document.querySelectorAll('.eliminar-producto').forEach(btn => {
      btn.addEventListener('click', () => {
        const index = btn.dataset.index;
        carrito.splice(index, 1);
        localStorage.setItem('carrito', JSON.stringify(carrito));
        renderizarCarrito();
      });
    });
  }

  if (botonVaciar) {
    botonVaciar.addEventListener('click', () => {
      localStorage.removeItem('carrito');
      renderizarCarrito();
    });
  }

  renderizarCarrito();
});
