const carrito = JSON.parse(localStorage.getItem('carrito')) || [];

function agregarAlCarrito(nombre, precio) {
  carrito.push({ nombre, precio });
  localStorage.setItem('carrito', JSON.stringify(carrito));
  alert(`${nombre} fue agregado al carrito.`);
}

document.addEventListener('DOMContentLoaded', () => {
  const lista = document.getElementById('lista-carrito');
  if (lista) {
    carrito.forEach(producto => {
      const div = document.createElement('div');
      div.className = 'producto-carrito';
      div.textContent = `${producto.nombre} - $${producto.precio}`;
      lista.appendChild(div);
    });
  }
});
