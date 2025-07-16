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

  document.addEventListener('DOMContentLoaded', () => {
    const filtros = document.querySelectorAll('.filtro');
    const productos = document.querySelectorAll('.producto');

    filtros.forEach(filtro => {
        filtro.addEventListener('click', function() {
            // Manejar la clase 'active' para el feedback visual
            filtros.forEach(f => f.classList.remove('active'));
            this.classList.add('active');

            const categoriaSeleccionada = this.getAttribute('data-categoria');

            // Filtrar productos
            productos.forEach(producto => {
                const categoriaProducto = producto.getAttribute('data-categoria');
                
                // Si la categoría coincide o se selecciona "Todos", mostrar el producto. Si no, ocultarlo.
                if (categoriaSeleccionada === 'Todos' || categoriaProducto === categoriaSeleccionada) {
                    // Usamos una pequeña demora para que la animación CSS se active
                    setTimeout(() => {
                        producto.classList.remove('hidden');
                        producto.style.display = 'flex';
                    }, 0);
                } else {
                    producto.classList.add('hidden');
                    // Esperar a que termine la animación antes de ocultarlo completamente
                    setTimeout(() => {
                        if (producto.classList.contains('hidden')) {
                            producto.style.display = 'none';
                        }
                    }, 400); // Este tiempo debe coincidir con la duración de la transición en CSS
                }
            });
        });
    });

    // Asegurarse de que al cargar la página todos los productos sean visibles
    const filtroActivo = document.querySelector('.filtro.active');
    if (filtroActivo && filtroActivo.getAttribute('data-categoria') === 'Todos') {
        productos.forEach(producto => {
            producto.classList.remove('hidden');
            producto.style.display = 'flex';
        });
    }
});