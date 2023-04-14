let button = document.querySelector('.top-button');

window.addEventListener('scroll', function() {
  if (document.documentElement.scrollTop > 100) {
    document.querySelector('.top-button').style.display = "block";
  } else {
    document.querySelector('.top-button').style.display = "none";
  }
});

button.addEventListener('click', function() {
  window.scrollTo({
    top: 0,
    behavior: 'smooth'
  });
});
