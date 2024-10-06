const express = require('express');
const bcrypt = require('bcrypt');

const app = express();
const port = 3000;

const users = [];

app.use(express.json());

app.post('/register', async (req, res) => {
    try {
        const { email, password } = req.body;
        const findUser = users.find((data) => data.email === email); 
        if (findUser) {
            return res.status(400).send("User Already Exists");
        }
        const hashPassword = await bcrypt.hash(password, 10);
        users.push({
            email,
            password: hashPassword
        });
        res.status(201).send("Created Successfully");

    } catch (err) {
        res.status(500).send({ message: err.message });
    }
});


app.post('/login',async (req,res)=>{
    try{
        const {email,password}=req.body;
        const findUser = users.find((data) => data.email === email); 
        if(!findUser){
            return res.status(400).send("User not found");
        }
        const passMatch = await bcrypt.compare(password,findUser.password);
        if(passMatch){
            res.status(200).send("logged in successfuly"); //replace with jdk token
        }else{
            res.status(400).send("Wrong email or password");
        }
    }catch(err){
        res.status(500).send({ message: err.message });
    }
})

app.listen(port, () => {
    console.log(`Server is running on port ${port}`);
});