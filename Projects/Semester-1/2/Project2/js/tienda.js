document.addEventListener('DOMContentLoaded', () => {
  const botonesAgregar = document.querySelectorAll('.agregar-carrito');

  botonesAgregar.forEach(boton => {
    boton.addEventListener('click', () => {
      const producto = boton.closest('.producto');
      const id = producto.dataset.id;
      const nombre = producto.dataset.nombre;
      const precio = parseFloat(producto.dataset.precio);

      let carrito = JSON.parse(localStorage.getItem('carrito')) || [];
      const existente = carrito.find(item => item.id === id);

      if (existente) {
        existente.cantidad += 1;
      } else {
        carrito.push({ id, nombre, precio, cantidad: 1 });
      }

      localStorage.setItem('carrito', JSON.stringify(carrito));
      mostrarMensaje(`${nombre} fue agregado al carrito.`);
    });
  });
});

function mostrarMensaje(texto) {
  const mensaje = document.createElement('div');
  mensaje.textContent = texto;
  mensaje.style.position = 'fixed';
  mensaje.style.bottom = '20px';
  mensaje.style.right = '20px';
  mensaje.style.background = '#00c3ff';
  mensaje.style.color = '#000';
  mensaje.style.padding = '10px 15px';
  mensaje.style.borderRadius = '5px';
  mensaje.style.boxShadow = '0 2px 8px rgba(0,0,0,0.3)';
  mensaje.style.zIndex = '999';
  document.body.appendChild(mensaje);

  setTimeout(() => {
    document.body.removeChild(mensaje);
  }, 2500);
}

  const filtros = document.querySelectorAll('.filtro');
  const productos = document.querySelectorAll('.producto');

  filtros.forEach(filtro => {
    filtro.addEventListener('click', () => {
      const categoriaSeleccionada = filtro.dataset.categoria;

      productos.forEach(producto => {
        const categoriaProducto = producto.dataset.categoria;

        if (categoriaSeleccionada === 'Todos' || categoriaProducto === categoriaSeleccionada) {
          producto.style.display = 'block';
        } else {
          producto.style.display = 'none';
        }
      });
    });
  });