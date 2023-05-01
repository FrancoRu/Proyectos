'use strict'

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


function* cont(){
    let i = 0;
    while(true){
        yield i++;
    }
}
let id = cont();
function template(creator, personName, project, deadline, importance, state){
    let row = document.createElement('tr');
    let identify = "id_" + id.next().value;
    let insert = `<td>${creator}</td>
        <td>${personName}</td>
        <td>${project}</td>
        <td>${deadline}</td>
        <td>${importance}</td>
        <td>${state}</td>
        <td><input type= "checkbox" id=${identify} onclick="addEvent('${identify}')"></td>
        `;
    row.innerHTML += insert;
    let doc = document.querySelector(".bodyTable");
    doc.appendChild(row);
}

let but = document.getElementById("btnSubmitInfo");
but.addEventListener('click', (event)=>{
    event.preventDefault();
    let creator = document.getElementById("inputName").value;
    let project = document.getElementById("inputNameProject").value;
    let personName = document.getElementById("inputResponsiblePersonName").value;
    let deadline = document.getElementById("inputDeadline").value;
    let importance = document.getElementById("inputImportance").value;
    if(creator != "" && project != "" &&personName != "" && deadline != "" && importance != ""){
        template(creator, personName, project, deadline, importance, "not started");
    }
});
function ocultar() {
    const divLogins = document.querySelectorAll(".login");
    divLogins.forEach(content => {
      if (content.getAttribute("id") !== "loginUser") {
        content.style.display = "none";
      }else{
        content.style.display = "flex";
      }
    });
}

function addEvent(identify){
    let input = document.getElementById(identify);
    input.addEventListener("change", ()=>{
        dataShow(input.parentNode.parentNode);
        removeCheck(identify);
    })
}
function dataShow(nodeParent) {
    const info = Array.from(nodeParent.children).map(child => child.textContent);
    const modify = document.querySelector("#updateDeleteLayout");
    const fields = ["#createdBy", "#responsiblePerson", "#project", "#deadline", "#importance"];
    fields.forEach((field, i) => modify.querySelector(field).textContent = info[i]);
    let checkbox = nodeParent.querySelector('input[type="checkbox"]');
    let identify = checkbox.getAttribute('id');
    modify.querySelector("#idTask").textContent = identify;
    document.querySelector("#stateDelete").textContent = nodeParent.children[5].textContent;
}

function removeCheck(identify){
    let input = document.querySelectorAll("td input[type='checkbox']");
    input.forEach(element=>{
        if(element.id !== identify){
            element.checked = false;
        }
    })
}

const btnSubmitModify = document.getElementById("BtnModify");
btnSubmitModify.addEventListener('click', (event)=>{
    event.preventDefault();
    const stateSelect = document.querySelector('#state');
    const selectedValue = stateSelect.value;
    let actual = document.querySelector("#updateDeleteLayout #idTask").textContent;
    let modify = document.querySelector(`input[type="checkbox"]#${actual}`).parentNode.parentNode;
    let row = modify.querySelectorAll('td');
    row[5].innerHTML = selectedValue;
})

const btnSubmitDelete = document.getElementById("BtnDelete");
btnSubmitDelete.addEventListener('click', (event) =>{
    event.preventDefault();
    let actual = document.querySelector("#updateDeleteLayout #idTask").textContent;
    let modify = document.querySelector(`input[type="checkbox"]#${actual}`).parentNode.parentNode;
    let tab = document.querySelector(".bodyTable");
    tab.removeChild(modify);
})

const btnRecoverPass = document.getElementById("btnSubmitRecPass");
btnRecoverPass.addEventListener('click', (event)=>{
    event.preventDefault();
    const emailInput = document.querySelector('#btnRecoverPass');
    const email = emailInput.value;
    console.log(email);
    alert(`Recovery email sent to: ${email}`);
    ocultar();
})

const btnCreateUser = document.getElementById("btnSubmitNewUser");
btnCreateUser.addEventListener('click', (event)=>{
    event.preventDefault();
    try {
        const nameUser = document.getElementById("nameCreateUser");
        if(nameUser.value == "") {
          throw new Error("username is required");
        }
        
        const passUser= document.getElementById("passCreateUser");
        const repeatPassUser= document.getElementById("repeatPassCreateUset");
        if(passUser.value === "" || repeatPassUser.value === "" ) {
          throw new Error("password is required");
        }
        
        if(passUser.value !== repeatPassUser.value) {
          throw new Error("Passwords do not match");
        }
        
        const emailUser= document.getElementById("emailCreateUser");
        if(emailUser.value === "") {
          throw new Error("email is required");
        }
        
        ocultar();

    } catch (error) {
        alert(error.message);
    }

})