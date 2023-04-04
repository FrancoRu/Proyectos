
const btnCrud = document.querySelectorAll('#CRUD input[type="button"]');
btnCrud.forEach(boton => {
    boton.addEventListener('click', event => {
        const blocks = document.querySelectorAll(".layouts");
        blocks.forEach(content =>{
            if(content.getAttribute("id")!== "CRUD") {
                content.style.display = 'none';
            }
        });
        let content = document.getElementById(event.target.dataset.target);
        if(event.target.dataset.target === "updateLayout"||event.target.dataset.target === "deleteLayout"){
            let form = document.querySelector("#updateDeleteLayout");
            form.style.display = 'flex';
        }
        content.style.display = 'flex';
    });
});
const tagA = document.querySelectorAll('.login a');
tagA.forEach(a => {
  a.addEventListener('click', event =>{
    const target = event.target.dataset.target;
    const blocks = document.querySelectorAll('.login');
    blocks.forEach(content => content.style.display = 'none');
    const content = document.getElementById(target);
    content.style.display = 'flex';
  });
});
const block = document.querySelectorAll('.layouts');
block.forEach(content => content.style.display = 'none');

const btnLogin = document.getElementById("btnSubmit");
btnLogin.addEventListener('click', ()=>{
    const log = document.querySelectorAll('.login');
    log.forEach(content => content.style.display = 'none');
    block.forEach(content => {
        if(content.getAttribute("id")==="CRUD") content.style.display = 'flex';
    })
})

function template(creator, personName, project, deadline, importance, state){
    let insert = `<tr>
        <td>${creator}</td>
        <td>${personName}</td>
        <td>${project}</td>
        <td>${deadline}</td>
        <td>${importance}</td>
        <td>${state}</td>
    </tr>`;
    let doc = document.querySelector(".bodyTable");
    doc.innerHTML += insert;
}

let but = document.getElementById("btnSubmitInfo");
but.addEventListener('click', (event)=>{
    event.preventDefault();
    let creator = document.getElementById("inputName").value;
    let project = document.getElementById("inputNameProject").value;
    let personName = document.getElementById("inputResponsiblePersonName").value;
    let deadline = document.getElementById("inputDeadline").value;
    let importance = document.getElementById("inputImportance").value;
    template(creator, personName, project, deadline, importance, "state");
});
function ocultar() {
    const divLogins = document.querySelectorAll(".login");
    divLogins.forEach(content => {
      if (content.getAttribute("id") !== "loginUser") {
        content.style.display = "none";
      }
    });
}
