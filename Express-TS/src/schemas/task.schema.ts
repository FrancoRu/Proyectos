import { z } from 'zod'
import mongoose from 'mongoose'
import { Importance, State } from '../types/types'

export const createTaskSchema = z.object({
  proyect: z
    .string({
      required_error: 'Proyect is required'
    })
    .min(1),
  title: z
    .string({
      required_error: 'Title is required'
    })
    .min(1),
  description: z.string(),
  assignedTo: z
    .string({
      required_error: 'username responsible is required'
    })
    .min(1),
  deadline: z.string().refine(
    (value) => {
      const parsedDate = new Date(value)
      return !isNaN(parsedDate.getTime()) // Verifica si es una fecha válida
    },
    {
      message: 'Debe ser una cadena de fecha válida'
    }
  ),
  importance: z.nativeEnum(Importance, {
    required_error: 'Importance is required'
  })
})

export const updateTaskSchema = z.object({
  proyect: z
    .string({
      required_error: 'Proyect is required'
    })
    .min(1)
    .nullable(),
  title: z
    .string({
      required_error: 'Title is required'
    })
    .min(1)
    .nullable(),
  description: z.string().nullable(),
  assignedTo: z
    .string({
      required_error: 'username responsible is required'
    })
    .min(1)
    .nullable(),
  deadline: z
    .string()
    .refine(
      (value) => {
        const parsedDate = new Date(value)
        return !isNaN(parsedDate.getTime()) // Verifica si es una fecha válida
      },
      {
        message: 'Debe ser una cadena de fecha válida'
      }
    )
    .nullable(),
  importance: z
    .nativeEnum(Importance, {
      required_error: 'Importance is required'
    })
    .nullable(),
  state: z
    .nativeEnum(State, {
      required_error: 'State is required'
    })
    .nullable()
})

export const objectIdSchema = z.string().refine(
  (value) => {
    try {
      mongoose.Types.ObjectId.createFromHexString(value)
      return true
    } catch (error) {
      return false
    }
  },
  {
    message: 'Must be a valid ObjectId'
  }
)
