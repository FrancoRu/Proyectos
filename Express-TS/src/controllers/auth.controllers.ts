import { Request, Response } from 'express'
import User from '../models/user.models'
import bcrypt from 'bcryptjs'

import { generateToken } from '../libs/token.libs.ts'
import { UserToken } from '../types/types'

interface RequestWithUserData extends Request {
  userData?: UserToken
}

export const register = async (req: Request, res: Response) => {
  const {
    email,
    password,
    username
  }: { email: string; password: string; username: string } = req.body

  try {
    const passwordHash = await bcrypt.hash(password, 10)

    const newUser = new User({
      username,
      email,
      password: passwordHash
    })

    const userSave = await newUser.save()
    const newToken = await generateToken({
      _id: userSave._id,
      username: userSave.username,
      email: userSave.email
    })
    res.cookie('token', newToken)
    res.status(201).json({
      message: 'user creatly successfuly'
    })
  } catch (error: any) {
    console.error(error)
    res.status(500).send('Error al registrar al usuario') // Respondemos con el código 500 en caso de error interno del servidor
  }
}

export const login = async (req: Request, res: Response) => {
  console.log('Hola')
  const { email, password }: { email: string; password: string } = req.body

  try {
    const userFound = await User.findOne({ email })
    if (!userFound) {
      return res.status(404).json({ message: 'User not found' })
    }

    const isMatch = await bcrypt.compare(password, userFound.password)

    if (!isMatch) {
      return res.status(401).json({ message: 'Invalid Credentials' })
    }

    const newToken = await generateToken({
      _id: userFound._id,
      username: userFound.username,
      email: userFound.email
    })

    res.cookie('token', newToken)
    return res.status(200).json({
      message: 'User login successfuly'
    })
  } catch (error: any) {
    console.error(error)
    return res.status(500).send('Error al registrar al usuario')
  }
}

export const logout = async (_req: Request, res: Response) => {
  res.cookie('token', '', {
    expires: new Date(0)
  })
  return res.sendStatus(200)
}

export const profile = async (_req: RequestWithUserData, res: Response) => {
  res.status(200).json({
    message: 'user authorized',
    ..._req.userData
  })
}
